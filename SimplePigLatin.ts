export const pigIt = (a : string) : string =>  {
  // code away
  let r: string[] = a.split(' ')
  .map((w, index) => { 
    let buf = w.split('').splice(1, w.split('').length - 1), temp = w.split('')[0];
    buf.push(temp);
    return (
      w.length > 1 ? (buf.join('') + "ay") 
      : (w.match(/[a-z]/i) ? w + "ay" : w)
    );
  });
  return r.join(' ');
}

