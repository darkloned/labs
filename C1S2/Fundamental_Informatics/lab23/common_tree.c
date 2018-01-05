#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define PARENT 0
#define SIBLING 1
#define ARRAYSIZE(x) (int) (sizeof(x) / sizeof(*x))

typedef struct Node
{
	char* value;

	struct Node* child;
	struct Node* sibling;

} Node;

Node* createNode(char* value)
{
        Node* node = (Node*) malloc(sizeof(Node));
        
        node->value = malloc(sizeof(value));
        strcpy(node->value, value);
        node->child = NULL;
        node->sibling = NULL;
        
        return node;
}

const char* addNode(Node** root, char (*cmd)[16], int cmdLength,  bool* emptyTree)
{        
        /* Examples:
         * 
         * "add root value 3" - create tree root node with value 3
         * "add childOf r 2 value 4" - create descendant of second root's child
         *                             with value 3
         */
        
        Node** node = root;

        if (cmdLength < 4)
        {
            return "Wrong amount of arguments";
        }
        else if ((strcmp(cmd[1], 	     "root")    != 0  &&
                  strcmp(cmd[1], 	     "childOf") != 0) || 
                  strcmp(cmd[cmdLength - 2], "value")   != 0   )
        {
            return "Unknown parameter";
        }
        else
        {
            if (strcmp(cmd[1], "root") == 0)
            {
                if (!*emptyTree)
                {
                    return "Root already exists";
                }
                else
                {
                    *root = createNode(cmd[3]);
                    *emptyTree = false;

                    return "Root added";
                }
            }
            else if (cmdLength < 5)
            {
                return "Wrong amount of arguments";
            }
            else // add childOf...
            {
                if (*emptyTree)
                {
                    return "No root found";
                }
                else if (strcmp(cmd[2], "root") != 0)
                {
                    return "Wrong path";
                }
                else
                {
                    for (int i = 3; i < cmdLength - 2; ++i) // to foo
                    {
                            int sibling = strtol(cmd[i], (char**) NULL, 10);

                            for (int j = 0; j < sibling; j++)
			    {
				    Node** nextNode = (j == 0) ? &((*node)->child) : &((*node)->sibling);

				    if (*nextNode == NULL)
				    {
					    return "No such parent";
				    }
				    else
				    {
					    node = nextNode;
				    }
			    }
                    }
                    
		    node = &((*node)->child);

		    while (*node != NULL)
		    {
			    node = &((*node)->sibling);
		    }
		    
		    *node = createNode(cmd[cmdLength - 1]);
                    
                    return "Node added";
                }
            }
        }
}

const char* removeNode(Node** root, char (*cmd)[16], int cmdLength,  bool* emptyTree)
{
    /* Example:
     * "rm r 2" - remove second child of root
     */
    
    Node** node = root;
    
    if (cmdLength < 2)
    {
        return "Wrong amount of arguments";
    }
    if (*emptyTree)
    {
        return "Tree is empty";
    }
    else if (strcmp(cmd[1], "root") != 0)
    {
        return "Wrong path";
    }
    else
    {
        if (cmdLength == 2)
        {
            free(*root);
            *root = NULL;
            
            *emptyTree = true;

            return "Root removed";
        }
        else
        {
            Node** previousNode = root;
            int  previousNodeType = PARENT;
        
            for (int i = 2; i < cmdLength; ++i) // to foo
            {
                    int sibling = strtol(cmd[i], (char**) NULL, 10);

                    for (int j = 0; j < sibling; j++)
                    {
                            Node** nextNode = (j == 0) ? &((*node)->child) : &((*node)->sibling);

                            if (*nextNode == NULL)
                            {
                                    return "No such parent";
                            }
                            else
                            {
                                    previousNode = node;
                                    previousNodeType = (j == 0) ? PARENT : SIBLING;
                                    
                                    node = nextNode;
                            }
                    }
            }
            
            if (previousNodeType == PARENT)
            {
                (*previousNode)->child = (*node)->sibling;
            }
            else // SIBLING
            {
                (*previousNode)->sibling = (*node)->sibling;
            }
            
            // TODO: Remove redundant branch
            
            return "Node removed";
        }
    }
}

void printTree(Node* node, const int level)
{
    if (node->child != NULL)
    {
        printf("%*s%s\n", level, "", node->value);
        printTree(node->child, level + 1);
        
        if (node->sibling != NULL)
        {
            printTree(node->sibling, level);
        }
    }
    else if (node->sibling != NULL)
    {
        printf("%*s%s\n", level, "", node->value);
        printTree(node->sibling, level);
    }
    else
    {
        printf("%*s%s\n", level, "", node->value);
    }
}

bool isLinearList(Node* node)
{
    if (node->child != NULL && node->sibling == NULL)
    {
        return isLinearList(node->child);
    }
    else if (node->child == NULL && node->sibling != NULL)
    {
        return isLinearList(node->sibling);
    }
    else if (node->child == NULL && node->sibling == NULL)
    {
        return true;
    }
    else // if (node->child != NULL && node->sibling != NULL)
    {
        return false;
    }
}

void parseLine(char* cmdLine, const char* delim, char (*parsedLine)[16])
{
	int i = 0;
	char* token = strtok(cmdLine, delim);

	while (token != NULL)
	{
		strcpy(parsedLine[i], token);
		token = strtok(NULL, delim);
		i++;
	}
}


int main()
{
	bool emptyTree = true;
	Node* root = NULL;

	char cmdLine[1024];

	while (fgets(cmdLine, sizeof cmdLine, stdin) != NULL)
	{
		strtok(cmdLine, "\n"); // remove trailing newline char

		int tokenCount = 1;

		for (int i = 0; i < strlen(cmdLine); i++)
		{
			if (cmdLine[i] == ' ')
			{
				tokenCount++;
			}
		}

		char cmd[tokenCount][16];
		
		parseLine(cmdLine, " ", cmd);

		if (strcmp(cmd[0], "add") == 0)
		{
                        printf("%s\n", addNode(&root, cmd, ARRAYSIZE(cmd), &emptyTree));
                }
		else if (strcmp(cmd[0], "rm") == 0)
		{
			printf("%s\n", removeNode(&root, cmd, ARRAYSIZE(cmd), &emptyTree));
		}
		else if (strcmp(cmd[0], "print") == 0)
                {
                        if (emptyTree)
                        {
                            printf("%s\n", "Tree is empty");
                        }
                        else
                        {
                            printTree(root, 0);
                        }
                }
                else if (strcmp(cmd[0], "isLinearList") == 0)
                {
                    if (emptyTree)
                    {
                        printf("%s\n", "Tree is empty");
                    }
                    else
                    {
                        printf("%s\n", isLinearList(root) ? "True" : "False");
                    }
                }
                else if (strcmp(cmd[0], "exit") == 0)
                {
                        printf("%s\n", "Bye");
                        
                        return 0;
                }
		else
		{
			printf("%s\n", "Unknown directive");
		}
	}

	return 0;
}
