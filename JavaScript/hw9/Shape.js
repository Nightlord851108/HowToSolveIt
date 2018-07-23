class Shape{
    constructor(v, r = 0) {
        if (r == 0) {
            for(var i in v){
                if(!(v[i].dimension() == 2))
                    throw new Error('Dimension Error');
            }
            this.n = v.length;
            this.vertices = v;
        }
        else if(r > 0){
            if(v.dimension() != 2)
                throw new Error('Dimension Error');
            this.o = v;
            this.r = r;
        }
    }
};
