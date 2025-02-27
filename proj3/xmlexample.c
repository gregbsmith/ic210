/* IC210 Spring 2020
 * Example program using libxml2 to read in a small XML file.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libxml/parser.h>

int main() {
  // get the filename, same as always
  printf("Filename: ");
  char fname[128];
  scanf(" %s", fname);

  // read the entire file into a xmlDoc struct
  xmlDoc* document = xmlReadFile(fname, NULL, 0);

  // get the document root node
  xmlNode* root = xmlDocGetRootElement(document);
  printf("The root node name is %s\n", (char*)root->name);

  // go to the root's first child
  // added two ->next calls
  xmlNode* child = root->children->next;
  printf("The root's child's name is %s\n", (char*)child->name);

  // get the child's attributes
  xmlAttr* attr = child->properties;
  while (attr != NULL) {
    printf("The child has an attribute named %s\n", (char*)attr->name);
    printf("The attribute's value is %s\n", (char*)attr->children->content);
    // move to the next attribute
    attr = attr->next;
  }

  // go through the child's children
  xmlNode* gchild = child->children->next;
  while (gchild != NULL) {
    printf("The child has a child named %s\n", (char*)gchild->name);
    printf("That grandchild's contents are %s\n", (char*)gchild->children->content);
    // move to the next grandchild
    gchild = gchild->next->next;
  }

  // clean up
  xmlFreeDoc(document);

  return 0;
}
