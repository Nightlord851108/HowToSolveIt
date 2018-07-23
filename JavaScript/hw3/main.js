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

function length(v) {
    if (v.length < 1)
        throw new Error('Dimension less than 1');
    var s = 0;
    for (i in v) {
        s += v[i] * v[i];
    }
    return Math.sqrt(s);
}

function scalar(a, v) {
    if (v.length < 1)
        throw new Error('Dimension less than 1')
    var result = [];
    for (i in v)
        result.push(v[i] * a);
    return result;
}
