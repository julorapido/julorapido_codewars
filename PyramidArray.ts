export function pyramid(n: number) {
  // your code here
  var r_ : number[][] = new Array<Array<number>>(n);
  if(n == 0){return [];}
  for(let i = 0; i < n; i++){
    r_[i] = new Array<number>(i + 1); 
    r_[i][0] = 1;
    for(let j = 0; j < i + 1; j++){
      r_[i][j] = 1;
    }
  }
  return r_;
}
