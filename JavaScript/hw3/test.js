describe('Test Sum', function() {
    it ('Normal', function() {
        var a = [1, 2];
        var b = [2, 3];
        var s = sum(a, b);
        expect([3, 5]).toEqual(s);
    });
    it ('Exception', function(){
        var a = [1, 2];
        var b = [2, 3, 4];
        var error = function() {
            sum(a,b);
        }
        expect(error).toThrow();
    });
});

describe('Test product', function() {
    it ('Normal', function() {
        var u = [2, 3];
        var v = [1, 2];
        expect(8).toEqual(product(u,v));
    });
    it ('Exception', function() {
        var error = function() {
            product([1, 2], [1, 2, 3]);
        }
        expect(error).toThrow(Error('Dimension error'));
    });
});

describe ('Prove', function() {
    it ('Prove1', function() {
        var u = [1, 2];
        var v = [3, 4];
        var w = [5, 6];
        var left = product(u, sum(v, w));
        var right = product(u, v) + product(u, w);
        expect(left).toEqual(right);
    });
    it ('Prove2', function() {
        var u = [1, 2];
        var v = [3, 4];
        var left = Math.pow(length(sum(u, v)), 2);
        var right = Math.pow(length(u), 2) + 2 * product(u, v) + Math.pow(length(v), 2);
        expect(left).toBeCloseTo(right);
    });
});

describe('Test Length', function() {
    it ('Normal', function() {
        var v = [3, 4];
        expect(5).toEqual(length(v));
    });
    it ('Exception', function() {
        var error = function() {
            var v = [];
            length(v);
        }
        expect(error).toThrow(Error('Dimension less than 1'));
    });
});

describe('Test Scalar', function() {
    it ('Normal', function() {
        var v = [1,1];
        expect([2, 2]).toEqual(scalar(2, v));
    });
    it ('Exception', function() {
        var v = [];
        var error = function() {
            scalar(2, v);
        }
        expect(error).toThrow(Error('Dimension less than 1'));
    });
});
