function hexStringToRGB(hexString) {
    var res = {r: 0, g:0, b: 0}; let cnt = 0;
    for (let i = 1; i < hexString.split('').length - 1; i = i + 2){
        const nmbr = parseInt(hexString.split('')[i] + hexString.split('')[i + 1] , 16);
        res[Object.keys(res)[cnt]] = nmbr;
        cnt++;
    }
    return res
  }