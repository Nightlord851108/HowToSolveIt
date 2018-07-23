class Vector{
    constructor(v){
        if (v.length < 1)
            throw new Error('Dimension less than 1');
        this.dim = v.length;
        this.comp = v;
    }

    dimension(){
        return this.dim;
    }

    component(opts = {}){
        if(!opts['index'])
            return this.comp;
        return this.comp[opts['index']-1];
    }

    length(){
        var s = 0;
        for(var i in this.comp)
            s += this.comp[i] * this.comp[i];
        return Math.sqrt(s);
    }

    scalar(a) {
        var v = [];
        for (i in this.comp) {
            v.push(this.comp[i] * a);
        }
        return new Vector(v);
    }

    static sum (v1, v2) {
        if (v1.dimension() != v2.dimension())
            throw new Error('Dimension error');
        var v = [];
        for (var i in v1.component()) {
            v.push(v1.component()[i] + v2.component()[i]);
        }
        return new Vector(v);
    }

    static productDot(v1, v2) {
        if (v1.dimension() != v2.dimension())
            throw new Error('Dimension error');
        var s = 0;
        for (var i in v1.component()) {
            s += v1.component()[i] * v2.component()[i];
        }
        return s;
    }
}
function getVector(s){
    if((s.charAt(0) !== '(') || (s.charAt(s.length - 1) !== ')'))
        throw new Error('Format Error');
    s = s.substring(1, s.length - 1);
    s = s.split(',');
    v = [];
    for(i = 0; i < s.length; i++)
        v.push(parseInt(s[i]));
    return new Vector(v);
}
