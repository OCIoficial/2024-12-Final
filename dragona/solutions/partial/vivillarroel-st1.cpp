// This file is a partial solution for the sample task. You can add partial
// solutions just by placing them in this directory. Remove this file before
// you start working on the actual task.
//
// Partial solutions must specify the list of subtasks they should fail with a
// comment as exemplified below. Ocimatic will check the solution fails these
// subtasks and only these subtasks. If no comment is present, ocimatic will
// assume all subtasks should fail.
//
// For the sample task, this solution should fail the subtask 2 because it uses
// `int` instead of `long`. This implies the solution should pass subtask 1.

// @ocimatic should-fail=[st2,st3,st4]
#include <iostream>

using namespace std;

int main() {
	int n, h;
	cin >> n >> h;
	if (n == 0) {
		cout << h-1 << endl;
	}
	else {
		int a, b;
		cin >> a >> b;
		cout << h-1-(b-a) << endl;
	}
	return 0;
}
