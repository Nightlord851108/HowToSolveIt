function square (x) {
    if (typeof(x) == 'number')
        return x * x;
    if (typeof(x) == 'object') {
        var a = [];
        for(var i in x) {
            a.push(square(x[i]));
        }
        return a;
    }
}

function isPositive(a) {
    return a >=0;
}

function findAll(a, n, scape, foo) {
    if (typeof(foo) != 'function')
        throw new Error ('Not a function!');
    var result = []
    for (var i = 0; i < n; i += 1 + scape) {
        if (foo(a[i]))
            result.push(a[i]);
    }
    return result;
}
