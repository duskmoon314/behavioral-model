#ifndef _BM_SIMPLE_SWITCH_PRIMITIVES_H_
#define _BM_SIMPLE_SWITCH_PRIMITIVES_H_

class modify_field : public ActionPrimitive<Field &, const Data &> {
  void operator ()(Field &f, const Data &d) {
    f.set(d);
  }
};

REGISTER_PRIMITIVE(modify_field);

class drop : public ActionPrimitive<> {
  void operator ()() {
    get_field("standard_metadata.egress_spec").set(0);
  }
};

REGISTER_PRIMITIVE(drop);

#endif
