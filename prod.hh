#ifndef PROD_HH
#define PROD_HH

using std::shared_ptr;

struct prod_visitor {
  virtual void visit(struct prod *p) = 0;
  virtual ~prod_visitor() { }
};

struct prod {
  struct prod *pprod;
  struct scope *scope;
  int level;
  prod(prod *parent) : pprod(parent) {
    if (parent) {
      level = parent->level + 1;
      scope = parent->scope;
    } else {
      scope = 0;
      level = 0;
    }
  }
  virtual void out(std::ostream &out) = 0;
  virtual void accept(prod_visitor *v) { v->visit(this); }
};

std::ostream& operator<<(std::ostream& s, struct prod& p);

#endif