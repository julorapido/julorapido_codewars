
using System;
using System.Text;

public class Kata
{
  public static string[] TowerBuilder(int nFloors)
  {
    string[] res = new String[nFloors];
    
    int ii = 0;
    for(int f = 0; f < nFloors; f++)
    {
      if(nFloors == 1) break;
      
      StringBuilder res_f = new StringBuilder("ABC", (nFloors * 2) - 1 );
      int o = (f > 0 ? f : 1 )+ (2 * ii);
      // x ==> map
      int len = (nFloors * 2) - 1;
      for(int i = 0; i < len; i ++)
      {
        if(i >= len - (o == 1 ? 2 : o) )
        { 
          res_f[i] = '*';
          o --;
        } else { res_f[i] = ' '; }
        
      } 
      ii++;
      Console.WriteLine(res_f.ToString() + " vs " + res.Length +  " vs " + f);
      res[f] = res_f.ToString();
    }
    return nFloors == 1 ? new string[] { "*" } : res;
  }
}


