function isSolved(board) {
  let res = 0 , z = false, d = null, d_v = 1;
  board.map((t, w) => { 
    let a = [0, 0, 0], b = [0, 0, 0];
    t.map((x, i) => { a[board[w][i]]++; }); // x
    t.map((y, j) => { b[board[w][j]]++; }); // y

    let r = a.findIndex((el, h) => el == 3 && h != 0) || b.findIndex((el, h) => el == 3 && h != 0);
    if(!z) { if(t.findIndex(el => el == 0) != -1) z = true; }
    if(r != -1){ res = r;}
  });
  
  board.map((o, l) => { 
    if(d == null){ d = board[l][l];}else{ if(board[l][l] == d)  d_v++; }
  });
  if(d_v == 3) res = d;

  return res == 0 ? (z ? -1 : 0) : res;
}

