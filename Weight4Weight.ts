export function orderWeight(strng: string): string {
    // Your code
    let res = [];
    for (let i = 0; i < strng.split(' ').length; i ++){
      let w = 0;
      for (let p = 0; p < strng.split(' ')[i].split('').length; p ++){
        w += parseInt(strng.split(' ')[i].split('')[p]);
      }
      res.push({[ strng.split(' ')[i]] : w});
    }
    res = res.sort((a,b) => Object.values(a)[0] -  Object.values(b)[0]);
    let newRes = [];let useInt : number = Object.values(res[0])[0];
    for (let c = 0; c < res.length; c ++){
        useInt = Object.values(res[c])[0];
        if (c !== res.length -1){
          if (useInt !== Object.values(res[c + 1])[0]){
              let arr = [];
              for (let p =0; p < c + 1; p++){
                if (useInt === Object.values(res[p])[0]){
                    arr.push(Object.keys(res[p])[0]);
                }
              }
            arr = arr.sort();
            for (let elements of arr.values()  ) {
              newRes.push(elements);
            }
          }
      }else{
        newRes.push( Object.keys(res[c])[0]);
      }
    }
    if (newRes.length !== res.length){
        let n = [ Object.keys(res[res.length - 1])[0], Object.keys(res[res.length - 2])[0] ] ;
        n = n.sort(); newRes.pop();
        newRes.push(n[0]);newRes.push(n[1]);
    }
    return newRes.join(' ');
  }