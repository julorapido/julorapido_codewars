export function bouncingBall(h: number, bounce: number, window: number): number {
    // your code
    let newH : number = h; let res : number = 0;
    if (h < 0 || !(bounce > 0 && bounce < 1) || window >= h){return -1}
    while (newH > window){
      res++;
      newH = newH * bounce;
      if (newH > window){res ++;}
    }
    return res;
}