using System;
using System.Text.Json;
using System.Text.Json.Serialization;


namespace StudentManager
{
    public class Group
    {
        public string Title {get; set;}
        public List<Student> Students {get; set;} = new List<Student>();

        public Group(string title)
        {
            Title = title;
        }

        public void AddStudent(Student newStudent)
        {
            Students.Add(newStudent);
        }

        public void ShowAllStudents()
        {
            if (Students.Count == 0)
            {
                Console.WriteLine("нет студентов");
                return;
            }

            foreach(var student in Students)
            {
                Console.WriteLine($"-----{student.ClassName} {student.StudentId}----");
                student.WriteToConsole();
                Console.WriteLine("--------------");
            }
        }

        public void DeleteAllStudents()
        {
            Students.Clear();
            Console.WriteLine("все обучающиеся удалены");
        }

        private string _getPath()
        {
            Console.Write("имя файла: ");

            string? input = Console.ReadLine();
            string fileName = !string.IsNullOrEmpty(input) ? input : "data.json";

            string directory = "static";
            if (!Directory.Exists(directory))
            {
                Directory.CreateDirectory(directory);
            }

            string filePath = Path.Combine(directory, fileName);

            return filePath;
        }

        public void SaveAllStudents()
        {
            try
            {
                string filePath = _getPath();
                
                var options = new JsonSerializerOptions
                {
                    WriteIndented = true,
                };

                string json = JsonSerializer.Serialize(Students, options);
                File.WriteAllText(filePath, json);
                
                Console.WriteLine("Все обучающиеся сохранены!");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Не удалось сохранить файл: {ex.Message}");
            }
        }

        public void LoadStudents()
        {
            try
            {
                string filePath = _getPath();
                
                if (!File.Exists(filePath))
                {
                    Console.WriteLine("Файл не существует!");
                    return;
                }

                string json = File.ReadAllText(filePath);
                
                var loadedStudents = JsonSerializer.Deserialize<List<Student>>(json);
                
                if (loadedStudents != null)
                {
                    Students = loadedStudents;
                    
                    int maxId = Students.Count > 0 ? Students.Max(s => s.StudentId) : 0;
                    Student.SetCurrentId(maxId);
                    
                    Console.WriteLine($"{Students.Count} обучающихся было загружено");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Не удалось загрузить файл: {ex.Message}");
            }
        }
    }
}
