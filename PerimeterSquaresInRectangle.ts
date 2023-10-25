export const perimeter = (n:number):number => {
  if(n < 3) return n * 4;
  var n1 = 0; var n2 = 1;
  let ar : number[] = [1];
  for (let s = 0; s < n; s++)
  {
    let z = n1 + n2;
    n1 = n2;
    n2 = z;
    ar.push(z);
  }
  // your code
  return ((ar.reduce((b, a) => b + a, 0)) * 4);
}

