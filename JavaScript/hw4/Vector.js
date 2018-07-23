class Vector{
    constructor(v){
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
