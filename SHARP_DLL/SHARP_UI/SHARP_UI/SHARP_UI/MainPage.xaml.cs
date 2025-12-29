using System.Collections.ObjectModel;
using System.Runtime.InteropServices;

namespace SHARP_UI;

public class StudentDisplayItem
{
    public string Name { get; set; }
    public int NativeIndex { get; set; }
}


public partial class MainPage : ContentPage
{
    public MainPage()
    {
        InitializeComponent();
        BindingContext = this;
    }

    public ObservableCollection<StudentDisplayItem> StudentList { get; } = new();
    
    private void OnSelected()
    {
        if (SelectedStudent == null)
        {
            _clearFields();
            return;
        }
        
        var student = DyLibAssistant.GetStudent(SelectedStudent.NativeIndex);
        
        try
        {
            IdEntry.Text = student.StudentId.ToString();
            NameEntry.Text = student.GetName();
            SurnameEntry.Text = student.GetSurname();
            AgeEntry.Text = student.Age.ToString();

            GenderEntry.Text = student.Gender ? "М" : "Ж";

            GLInfoCheckBox.IsChecked = student.IsGroupLeader;

            EmailEntry.Text = student.GetEmail();
            PhoneEntry.Text = student.GetPhoneNumber();
        }
        finally
        {
            DyLibAssistant.FreeStudent(student);
        }
    }

    private void _clearFields()
    {
        IdEntry.Text = string.Empty;
        NameEntry.Text = string.Empty;
        SurnameEntry.Text = string.Empty;
        AgeEntry.Text = string.Empty;
        GenderEntry.Text = string.Empty;
        EmailEntry.Text = string.Empty;
        PhoneEntry.Text = string.Empty;
    }
    
    private StudentDisplayItem _selectedStudent;
    public StudentDisplayItem SelectedStudent
    {
        get => _selectedStudent;
        set
        {
            if (_selectedStudent != value)
            {
                _selectedStudent = value;
                OnPropertyChanged();
                OnSelected();
            }
        }
    }

    public void FillStudentNames()
    {
        var nativeArray = DyLibAssistant.get_studentNames();

        try
        {
            StudentList.Clear();

            for (var i = 0; i < nativeArray.size; i++)
            {
                var ptr = Marshal.ReadIntPtr(nativeArray.data, i * IntPtr.Size);
                var name = Marshal.PtrToStringAnsi(ptr) ?? string.Empty;

                StudentList.Add(new StudentDisplayItem { Name = name, NativeIndex = i });
            }
        }
        finally
        {
            DyLibAssistant.free_string_array(nativeArray);
        }
    }
    
    private void OnExtendedInfoChanged(object sender, CheckedChangedEventArgs e)
    {
        var isChecked = e.Value;
        
        EmailLabel.IsVisible = isChecked;
        EmailBorder.IsVisible = isChecked;
        PhoneLabel.IsVisible = isChecked;
        PhoneBorder.IsVisible = isChecked;
    }
    
    public async void OnLoadClicked(object sender, EventArgs e)
    {
        try
        {
            var result = await FilePicker.Default.PickAsync();

            if (result == null) return;

            var res = DyLibAssistant.LoadStudentsFromFile(result.FullPath);
            if (res)
                FillStudentNames();
        }
        catch (Exception exp)
        {
            Console.WriteLine(value: exp.Message);
            await DisplayAlert(title: "Информация", message: "Выбор файла отменен", cancel: "OK");
        }
    }
    
    private void OnSaveClicked(object sender, EventArgs e)
    {
        DisplayAlert(title: "Info", message: "Save functionality", cancel: "OK");
    }
    
    private void OnClearClicked(object sender, EventArgs e)
    {
        _clearFields();
        
        StudentList.Clear();
        
        DyLibAssistant.ClearAllStudents();
    }
    
    private void OnAddClicked(object sender, EventArgs e)
    {
        StudentList.Add(new StudentDisplayItem { Name=string.Empty, NativeIndex = -1});
    }
    
    private void OnAddGLClicked(object sender, EventArgs e)
    {
        Console.WriteLine("dsgg");
    }
    
    private void OnDeleteClicked(object sender, EventArgs e)
    {
        if (SelectedStudent==null) return;
        
        StudentList.Remove(item: SelectedStudent);
        OnClearClicked(sender: sender, e: e);
    }
}