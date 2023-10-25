function longestSlideDown (pyramid) {
    let pyramidSum = [];
    pyramid.forEach((elem, index) => {
     pyramidSum.push(
        elem.map((e) => {
          return index === pyramid.length - 1 ? e : 0;
        })
      );
    });
    console.log(pyramidSum);
    for (let i = pyramidSum.length - 2; i >= 0; i--) {
      for (let j = 0; j < pyramidSum[i].length; j++) {
        pyramidSum[i][j] =
          pyramid[i][j] +
          Math.max(pyramidSum[i + 1][j], pyramidSum[i + 1][j + 1]);
      }
    }
    return pyramidSum[0][0];
  }