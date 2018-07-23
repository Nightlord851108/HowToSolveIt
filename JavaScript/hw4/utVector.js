describe('Test Vector', function(){
    it('Constructor', function(){
        var v = new Vector([1, 2]);
        expect(2).toEqual(v.dimension());
        expect([1, 2]).toEqual(v.component());
        expect(1).toEqual(v.component({'index':1}));
        expect(2).toEqual(v.component({'index':2}));
    });
});

describe('Test Vector Length', function(){
    it('Normal', function(){
        var v = new Vector([3, 4]);
        expect(5).toEqual(v.length());
    });
});

describe('Test getVector', function(){
    it('Normal', function(){
        var s = '(1,2)';
        var v = getVector(s);
        expect(2).toEqual(v.dimension());
        expect(1).toEqual(v.component({'index':1}));
        expect(2).toEqual(v.component({'index':2}));
    });
    it('Exception', function(){
        var s = '1,2))';
        var error = function(){
            getVector(s);
        }
        expect(error).toThrow(Error('Format Error'))
    });
});
