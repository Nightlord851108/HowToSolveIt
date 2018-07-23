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
        for (var i in this.comp) {
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

    static sub (v1, v2) {
        var v = []
        for (var i in v1.component()) {
            v.push(v1.component()[i] - v2.component()[i]);
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

    static centroid(v){
        for(var i = 1; i < v.length; i++){
            if(v[0].dimension() != v[i].dimension())
                throw Error('Dimension Error');
        }
        var result = [];
        for(var i in v[0].component()){
            result.push(v[0].component()[i])
            for(var j = 1; j < v.length; j++){
                result[i] += v[j].component()[i];
            }
        }
        result = new Vector(result);
        return result.scalar(1 / v.length);
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

function zout(v1, v2){
    if(v1.dimension() != v2.dimension() || v1.dimension() != 2)
        throw new Error('Format Error');
    return (v1.component()[0] * v2.component()[1]) >= (v1.component()[1] * v2.component()[0]);
}

class smallAngleInFront{
    constructor(o, v){
        this.o = o;
        this.v = v;
    }
    compare(va, vb){
        var r = Vector.sub(this.v, this.o);
        var v1 = Vector.sub(va, this.o);
        var v2 = Vector.sub(vb, this.o);
        var theta1 = Math.acos(Vector.productDot(v1,r)/(v1.length() * r.length()));
        var theta2 = Math.acos(Vector.productDot(v2,r)/(v2.length() * r.length()));
        if(!zout(r,v1))
            theta1 = 2 * Math.PI - theta1;
        if(!zout(r,v2))
            theta2 = 2 * Math.PI - theta2;
        return theta1 < theta2;
    }
}

function sort(v){
    var o = Vector.centroid(v);
    var compare = new smallAngleInFront(o, v[0]);
    for(var i = 0; i < v.length-1; i++){
        for(var j = i+1; j < v.length; j++){
            if(!(compare.compare(v[i], v[j]))) {
                var temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}
