using System;


namespace StudentManager{
    public class Menu{
        private Group group;

        public Menu(){
            group = new Group("AS-23-05");
        }

        private void PrintMainMenu(){
            Console.WriteLine("\n\n---МЕНЮ---");
            Console.WriteLine("0 - Завершить программу");
            Console.WriteLine("1 - Добавить студента");
            Console.WriteLine("2 - Добавить старосту");
            Console.WriteLine("3 - Посмотреть всех обучающихся");
            Console.WriteLine("4 - Сохранить обучающихся в файл");
            Console.WriteLine("5 - Загрузить обучающихся из файла");
            Console.WriteLine("6 - Удалить всех обучающихся");
            Console.WriteLine("----------------\n");
        }

        public void MainMenu(){
            Console.WriteLine($"Группа: {group.Title}");

            while (true)
            {
                PrintMainMenu();

                int choice = Utils.ValidInt(0, 6);

                switch (choice)
                {
                    case 0:
                        Console.WriteLine("\nдо свидания!");
                        return;

                    case 1:
                        group.AddStudent(new Student(true));
                        break;
                    
                    case 2:
                        group.AddStudent(new GroupLeader(true));
                        break;
                    
                    case 3:
                        group.ShowAllStudents();
                        break;

                    case 4:
                        group.SaveAllStudents();
                        break;

                    case 5:
                        group.LoadStudents();
                        break;

                    case 6:
                        group.DeleteAllStudents();
                        break;
                    
                    default:
                        Console.WriteLine("\nневерный выбор!");
                        break;
                }
            }
        }
    }
}
