using System;
using System.Text.Json.Serialization;


namespace StudentManager
{
    public class GroupLeader : Student
    {
        public string Email { get; set; } = string.Empty;
        public string PhoneNumber { get; set; } = string.Empty;

        [JsonIgnore]
        public override string ClassName => "староста";
        [JsonIgnore]
        public new static string StaticClassName => "староста";

        public GroupLeader() : base() { }

        public GroupLeader(bool fromConsole) : base(fromConsole)
        {
            if (fromConsole)
            {
                Console.Write("Email: ");
                this.Email = Console.ReadLine() ?? string.Empty;
                
                Console.Write("Номер телефона: ");
                this.PhoneNumber = Console.ReadLine() ?? string.Empty;
            }
        }

        public override void WriteToConsole()
        {
            base.WriteToConsole();

            Console.WriteLine($"Email: {Email}");
            Console.WriteLine($"Номер телефона: {PhoneNumber}");
        }
    }
}
