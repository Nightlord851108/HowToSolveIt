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

describe('centroid', function(){
    it('Normal', function(){
        var v = [
            new Vector([2, 1]),
            new Vector([0, 1])
        ];
        expect([1, 1]).toEqual(Vector.centroid(v).component());
    })
    it('Exception', function(){
        var v = [
            new Vector([1, 2, 3]),
            new Vector([1, 1])
        ];
        var error = function(){
            Vector.centroid(v);
        }
        expect(error).toThrow(Error('Dimension Error'))
    });
});

describe('zout', function(){
    it('Normal', function(){
        var v1 = new Vector([1, 0]);
        var v2 = new Vector([2, 1]);
        expect(true).toEqual(zout(v1, v2));
        expect(false).toEqual(zout(v2, v1));
        v2 = new Vector([1, 0]);
        expect(zout(v1, v2)).toEqual(true);
    })

    it('Exception', function(){
        var v1 = new Vector([2, 1]);
        var v2 = new Vector([1, 0, 2]);
        var error = function(){
            zout(v1, v2);
        }
        expect(error).toThrow(Error('Format Error'));
    });
});

describe('smallAngleInFront', function(){
    it('Normal', function(){
        var v = [
            new Vector([0, 0]),
            new Vector([1, 0]),
            new Vector([1, 1])
        ];
        var o = Vector.centroid(v);
        var cmpr = new smallAngleInFront(o, v[0]);
        expect(true).toEqual(cmpr.compare(v[1], v[2]));
    });
});

describe('sort', function(){
    it('Normal', function(){
        var v = [
            new Vector([0,0]),
            new Vector([0,1]),
            new Vector([1,1]),
            new Vector([1,0])
        ]
        sortVector(v);
        expect([0,0]).toEqual(v[0].component());
        expect([1,0]).toEqual(v[1].component());
        expect([1,1]).toEqual(v[2].component());
        expect([0,1]).toEqual(v[3].component());
    });
});
