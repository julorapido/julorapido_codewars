using System;

public class Kata
{
  public static string BreakCamelCase(string str)
  {
    string s = str;
    int c = 0;
    // complete the function
    for(int i = 0; i < str.Length + c; i++) {
      if( Char.IsUpper(s[i]) )
      {
        s = s.Insert(i, " "); 
        i++; c++;
      } 
    } 
    return s;
  }
}



