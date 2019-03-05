package gotest

import (
    "testing"
    "test_project/src/gotest"
)

func Test_Devision_Normal(t *testing.T) {
    if i, e := gotest.Division(6, 2); i!=3 || e!=nil {
        t.Error("Expected i is three and e is nil, but get i=", i, " e= ", e)
    } else {
        t.Log("pass")
    }
}
