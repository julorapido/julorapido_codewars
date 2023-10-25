function spinWords(string){
    //TODO Have fun :)
    let newStr= '';
    string.split(' ').map(
      (w, index) => {
        newStr = newStr + (w.length > 4 ? (w.split('').reverse().join('') ) 
        : w) + (string.split(' ').length > 1 ? " " : "");
      }
    );
    if (string.split(' ').length > 1){ newStr = (newStr.split(' ')); newStr.pop();newStr = newStr.join(' ');}
    return newStr;
}