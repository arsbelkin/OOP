namespace StudentManager
{
    public static class Utils
    {
        public static int ValidInt(int minValue, int maxValue)
        {
            int value;

            while (true)
            {
                if (int.TryParse(Console.ReadLine(), out value) && 
                    value >= minValue && value <= maxValue)
                    {
                        return value;
                    }
                    Console.WriteLine($"Ошибка! Введите число от {minValue} до {maxValue}");
            }
        }
    }
}
