using System;

public class Kata
{
  public static char FindMissingLetter(char[] array)
  {
    int l_int = (int)array[0];
    for(int i = 1; i < array.Length; i ++)
    {
      if( (array[i] - l_int ) < 2) l_int = array[i];
      else return ((char) (array[i] - 1) );
      // Console.WriteLine(((int)array[i]) + " vs " + array[i]);
    }
    return ' ';
  }
}


