using System.Runtime.InteropServices;

namespace SHARP_UI;

[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
public struct HelpStruct
{
    [MarshalAs(UnmanagedType.U1)]
    public bool IsGroupLeader;
    
    public int StudentId;
    public IntPtr Name;
    public IntPtr Surname;
    public int Age;
    
    [MarshalAs(UnmanagedType.U1)]
    public bool Gender;
    public IntPtr Email;
    public IntPtr PhoneNumber;
    
    public string GetName() =>  Marshal.PtrToStringAnsi(Name) ?? "";
    public string GetSurname() =>  Marshal.PtrToStringAnsi(Surname) ?? "";
    public string GetEmail() =>  Marshal.PtrToStringAnsi(Email) ?? "";
    public string GetPhoneNumber() =>  Marshal.PtrToStringAnsi(PhoneNumber) ?? "";
}


[StructLayout(LayoutKind.Sequential)]
public struct StringArray
{
    public IntPtr data;
    public int size;
}