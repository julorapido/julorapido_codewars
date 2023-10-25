export function inArray(a1: string[], a2: string[]): string[] {
    var res : string[] = [];
  
    for (let i = 0; i < a1.length; i++){
      for (let j = 0; j < a2.length; j ++){
        if (a2[j].includes(a1[i]) && (!res.includes(a1[i]))){
          res.push(a1[i]);
        }
      }
    }
    res = res.sort()
    return res
  }