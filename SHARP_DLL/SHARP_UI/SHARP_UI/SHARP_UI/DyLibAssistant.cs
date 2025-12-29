using System.Runtime.InteropServices;

namespace SHARP_UI;


public static class DyLibAssistant
{
    private const string LibPath = 
        "/Users/arsbelkin/OOPP/OOP/SHARP_DLL/StudentDyLib/cmake-build-debug/libStudentDyLib.dylib";
    
    [DllImport(LibPath, CallingConvention = CallingConvention.Cdecl)]
    public static extern bool LoadStudentsFromFile([MarshalAs(UnmanagedType.LPUTF8Str)] string pathToFile);
    
    [DllImport(LibPath, CallingConvention = CallingConvention.Cdecl)]
    public static extern StringArray get_studentNames();

    [DllImport(LibPath, CallingConvention = CallingConvention.Cdecl)]
    public static extern void free_string_array(StringArray array);
    
    [DllImport(LibPath, CallingConvention = CallingConvention.Cdecl)]
    public static extern HelpStruct GetStudent(int index);
    
    [DllImport(LibPath, CallingConvention = CallingConvention.Cdecl)]
    public static extern void FreeStudent(HelpStruct s);
    
    [DllImport(LibPath, CallingConvention = CallingConvention.Cdecl)]
    public static extern void ClearAllStudents();
}