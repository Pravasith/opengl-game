#include "Recruiter.h"
#include <iostream>
#include <string>
#include <vector>

Recruiter::Recruiter() {}
Recruiter::~Recruiter() {}

void Recruiter::SetRecruiter(int data) { __recruiter = data; }

void Recruiter::GetRecruiter(int &data) { data = __recruiter; }

int Recruiter::GetRecruiter() { return __recruiter; }
