describe('Test Vector', function(){
    it('Constructor', function(){
        var v = new Vector([1, 2]);
        expect(2).toEqual(v.dimension());
        expect([1, 2]).toEqual(v.component());
        expect(1).toEqual(v.component({'index':1}));
        expect(2).toEqual(v.component({'index':2}));
    });
    it ('Exception', function() {
        var error = function() {
            new Vector([]);
        }
        expect(error).toThrow(Error('Dimension less than 1'));
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

describe('Test Vector Sum', function() {
    it('Normal', function() {
        var v1 = new Vector([1, 2]);
        var v2 = new Vector([2, 3]);
        expect([3, 5]).toEqual(Vector.sum(v1, v2).component());
    });
    it ('Exception', function() {
        var v1 = new Vector([1, 2]);
        var v2 = new Vector([1, 2, 3]);
        var error = function() {
            Vector.sum(v1, v2);
        }
        expect(error).toThrow(Error('Dimension error'));
    });
});

describe('Product dot', function() {
    it ('Normal', function() {
        var v1 = new Vector([1, 2]);
        var v2 = new Vector([2, 3]);
        expect(8).toEqual(Vector.productDot(v1, v2));
    });
    it ('Exception', function() {
        var v1 = new Vector([1, 2, 3]);
        var v2 = new Vector([1, 2]);
        var error = function() {
            Vector.productDot(v1, v2);
        }
        expect(error).toThrow(Error('Dimension error'));
    });
});

describe('scalar', function() {
    it ('Normal', function() {
        var v1 = new Vector([1, 2]);
        expect([2, 4]).toEqual(v1.scalar(2).component());
    });
});
