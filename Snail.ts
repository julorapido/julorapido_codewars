const snail = (array : number[]) => {
    let res: number[] = [];
    if (array.length < 2){return array[0]}
    for (let i : number = 0; i < Math.floor(array.length / 2); i++){
      let n_ : number[] = []; let n : number[] = []; let m : number[] = [];
        let o : number[] = []; let p : number[]  = [];
      for (let a = 0; a < array.length - i - 1 - i; a++){
        o.push(array[array.length - i - 1][array.length - i - 1 - a]);
        if ( a < array.length - i - i){
            p.push(array[array.length - i - 1 - a][i]);
        }
      }
      for (let b : number = i; b < array.length - i - 1; b++){
        n.push(array[i][b]);
        m.push(array[b][array.length - i - 1]);
      }
      n_ = n_.concat(n); n_ = n_.concat(m); n_ = n_.concat(o); n_ = n_.concat(p);
      res = res.concat(n_);   
      
      if (i ==  Math.floor(array.length / 2) - 1){
       let v = array[Math.floor(array.length / 2)][Math.floor(array.length / 2)];
        if (res[res.length - 1] !== v && res[res.length - 2] !== v){ res.push(v);}
      }
      
    } 
  
    return res
  }