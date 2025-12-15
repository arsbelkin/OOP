using System.Collections.ObjectModel;
using Microsoft.Maui.Controls;

namespace SHARP_UI;

public partial class MainPage : ContentPage
{
    private ObservableCollection<string> StringList { get; } = new ObservableCollection<string>
    {
        "John Doe", "Jane Smith", "Bob Johnson", "Alice Brown", "Charlie Wilson"
    };
    
    private string _selectedString = string.Empty;
    public string SelectedString
    {
        get => _selectedString;
        set
        {
            _selectedString = value;
            OnPropertyChanged();
            OnSelected();
        }
    }
    
    public MainPage()
    {
        InitializeComponent();
        BindingContext = this;
    }
    
    private void OnExtendedInfoChanged(object sender, CheckedChangedEventArgs e)
    {
        bool isChecked = e.Value;
        
        EmailLabel.IsVisible = isChecked;
        EmailBorder.IsVisible = isChecked;
        PhoneLabel.IsVisible = isChecked;
        PhoneBorder.IsVisible = isChecked;
    }
    
    private void OnSelected()
    {
        if (string.IsNullOrEmpty(SelectedString)) return;
        
        NameEntry.Text = SelectedString;
        SurnameEntry.Text = "User";
        AgeEntry.Text = "30";
        IdEntry.Text = "001";

        if (!ExtendedInfoCheckBox.IsChecked) return;
        
        EmailEntry.Text = $"{SelectedString.ToLower().Replace(" ", ".")}@example.com";
        PhoneEntry.Text = "+1 (555) 123-4567";
    }
    
    private void OnLoadClicked(object sender, EventArgs e)
    {
        DisplayAlert("Info", "Load functionality", "OK");
    }
    
    private void OnSaveClicked(object sender, EventArgs e)
    {
        DisplayAlert("Info", "Save functionality", "OK");
    }
    
    private void OnClearClicked(object sender, EventArgs e)
    {
        IdEntry.Text = string.Empty;
        NameEntry.Text = string.Empty;
        SurnameEntry.Text = string.Empty;
        AgeEntry.Text = string.Empty;
        EmailEntry.Text = string.Empty;
        PhoneEntry.Text = string.Empty;
    }
    
    private void OnAddClicked(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(NameEntry.Text)) return;
        
        StringList.Add(NameEntry.Text);
    }
    
    private void OnChangeClicked(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(SelectedString) || string.IsNullOrEmpty(NameEntry.Text)) return;
        
        var index = StringList.IndexOf(SelectedString);
        if (index < 0) return;
        
        StringList[index] = NameEntry.Text;
    }
    
    private void OnDeleteClicked(object sender, EventArgs e)
    {
        if (string.IsNullOrEmpty(SelectedString)) return;
        
        StringList.Remove(SelectedString);
        OnClearClicked(sender, e);
    }
}
