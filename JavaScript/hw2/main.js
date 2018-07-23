function sum(a, b){
    if (a.length != b.length)
        throw new Error();
    var s = [];
    for(i = 0; i < a.length; i++){
        s.push(a[i] + b[i]);
    }
    return s;
}

function product(a,b) {
    if (a.length != b.length)
        throw new Error('Dimension error');
    var s = 0;
    for (i = 0; i < a.length; i++)
        s += a[i] * b[i];
    return s;
}
