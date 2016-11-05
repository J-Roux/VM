#include <stdint.h>
#include "parser.h"
struct Node {
  void* data;

  struct Node* nextSibling;
  struct Node* prevSibling;
  struct Node* parent;
};


struct Node* createNode(struct Node* expr0, struct Node* expr1, enum yytokentype type)
{
    return 0;
}
