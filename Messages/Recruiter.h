#pragma once

class Recruiter {
public:
  Recruiter();
  ~Recruiter();

  void SetRecruiter(int data);
  void GetRecruiter(int &data);
  int GetRecruiter();

private:
  int __recruiter;
};
