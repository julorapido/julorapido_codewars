using System;

public static class Kata
{
  public static string ReverseWords(string str)
  {
    string[] n_str = str.Split(' ');
    for(int i = 0; i < n_str.Length; i ++)
    {
        char[] stringArr = n_str[i].ToCharArray();
        Array.Reverse(stringArr);
        string reversed = new string(stringArr);
      
      n_str[i] = reversed;
    }
    return string.Join(" ", n_str);
  }
}


