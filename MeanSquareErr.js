var solution = function(firstArray, secondArray) {
    var res = 0;
    for (let i = 0; i < firstArray.length; i ++){
        let p = firstArray[i] - secondArray[i];
        res += Math.pow(p, 2);
    }
    return res/firstArray.length;
}