function nextBigger(n){
  let m = n.toString().split('');
  let i, j;
  for(i = m.length - 1; i > 0; i --){
    if(parseInt(m[i]) > parseInt(m[i - 1]) )break;
  }
  i--;
  
  let r_ = m.splice(i), pv =r_.splice(0,1)[0];
  // lowest [value, index]
  let vi = [null, null];
  
  for(let j = 0; j < r_.length; j ++){
      if(r_[j] > pv)
      {
        if (vi[0] == null || r_[j] < vi[0] )
        {
          vi[0] = r_[j];
          vi[1] = j;
        }
      }
  }
  if(vi[1] == null) return -1;
  // swap
  r_.splice(vi[1], 1);
  r_.push(pv);
  r_ = r_.sort();
  
   // concat the left + new pivot + right part
  var res = +m.concat([vi[0]]).concat(r_).join('');
  if (res < n) return -1;
  
  return res
}
