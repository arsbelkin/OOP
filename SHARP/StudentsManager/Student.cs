using System;
using System.Text.Json.Serialization;


namespace StudentManager
{
    [JsonDerivedType(typeof(Student), typeDiscriminator: "student")]
    [JsonDerivedType(typeof(GroupLeader), typeDiscriminator: "groupleader")]
    public class Student
    {
        private static int currentStudentId = 0;

        public int StudentId { get; set; }
        public string Name {get; set;} = string.Empty;
        public string Surname { get; set; } = string.Empty;
        public int Age { get; set; }
        public bool Gender { get; set; }

        [JsonIgnore]
        public virtual string ClassName => "студент";
        [JsonIgnore]
        public static string StaticClassName => "студент";

        public Student() {}

        public Student(bool fromConsole)
        {
            if (fromConsole)
            {
                this.StudentId = ++currentStudentId;
                Console.WriteLine($"ID: {this.StudentId}");
                
                Console.Write("Имя: ");
                this.Name = Console.ReadLine() ?? string.Empty;
                
                Console.Write("Фамилия: ");
                this.Surname = Console.ReadLine() ?? string.Empty;
                
                Console.Write("Возраст: ");
                this.Age = Utils.ValidInt(1, 120);
                
                Console.Write("Пол (0-Ж, 1-М): ");
                this.Gender = Convert.ToBoolean(Utils.ValidInt(0, 1));
            }
        }

        public virtual void WriteToConsole()
        {
            Console.WriteLine($"ID: {StudentId}");
            Console.WriteLine($"Имя: {Name}");
            Console.WriteLine($"Фамилия: {Surname}");
            Console.WriteLine($"Возраст: {Age}");
            Console.WriteLine($"Пол: {(Gender ? "М" : "Ж")}");
        }

        public static void SetCurrentId(int newId) 
        {
            currentStudentId = newId;
        }
    }
}
