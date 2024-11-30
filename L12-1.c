#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *protocol;
    char *host;
    char *pathname;
    char *search;
    char *hash;
    int port;
} Location;

Location *parse_url(char *url);

int main()
{
    char url[500] = "";
    fgets(url, 500, stdin); // Get url string
    Location *l = parse_url(url);
    printf("Location {\n  protocol: %s,\n  host: %s,\n", l->protocol, l->host);
    if (l->port)
        printf("  port: %d,\n", l->port);
    else
        printf("  port: (default),\n");
    printf("  pathname: /%s,\n  search: ?%s,\n  hash: #%s,\n}\n", l->pathname, l->search, l->hash);
    return 0;
}
Location *parse_url(char *url){
    Location *loc = malloc(sizeof(Location));
    loc->protocol = malloc((sizeof(char) * (strlen(url) + 1)));
    loc->host = malloc((sizeof(char) * (strlen(url) + 1)));
    loc->pathname = malloc((sizeof(char) * (strlen(url) + 1)));
    loc->search = malloc((sizeof(char) * (strlen(url) + 1)));
    loc->hash = malloc((sizeof(char) * (strlen(url) + 1)));

    strcpy(loc->protocol, "");
    strcpy(loc->host, "");
    strcpy(loc->pathname, "");
    strcpy(loc->search, "");
    strcpy(loc->hash, "");
    loc->port = 0;

    char *url_copy = url;
    char *ptr;

    url[strcspn(url, "\n")] = '\0';

    ptr = strstr(url_copy, "://");
    if (ptr){
        *ptr = '\0';
        strcpy(loc->protocol, url_copy);
        url_copy = ptr + 3;
    }

    
    ptr = url_copy;
    while (*ptr != '/' && *ptr != '?' && *ptr != '#' && *ptr != '\0'){
        ptr += 1;
    }
    char c = *ptr;
    
    
    if (ptr){
        *ptr = '\0';
    }
    char *host_port = url_copy;
    url_copy = ptr ? ptr + 1 : NULL;
    char *ptr1;
    ptr1 = strchr(host_port, ':');
    if (ptr1){
        *ptr1 = '\0';
        strcpy(loc->host, host_port);
        loc->port = atoi(ptr1 + 1);
    }
    else{
        strcpy(loc->host, host_port);
    }

    url_copy = ptr;
    *url_copy = c;

    if (url_copy){
        char *path_start = strchr(url_copy, '/');
        if (path_start){
            char *query_start = strchr(path_start, '?');
            if (query_start){
                *query_start = '\0';
                strcpy(loc->pathname, path_start + 1);
                char *hash_start = strchr(query_start + 1, '#');
                if (hash_start){
                    *hash_start = '\0';
                    strcpy(loc->search, query_start + 1);
                    strcpy(loc->hash, hash_start + 1);
                }
                else{
                    strcpy(loc->search, query_start + 1);
                }
            }
            else
            {
                char *hash_start = strchr(path_start, '#');
                if (hash_start){
                    *hash_start = '\0';
                    strcpy(loc->pathname, path_start + 1);
                    strcpy(loc->hash, hash_start + 1);
                }
                else{
                    strcpy(loc->pathname, path_start + 1);
                }
            }
        }
        else{
            char *query_start = strchr(url_copy, '?');
            if (query_start){
                *query_start = '\0';
                char *hash_start = strchr(query_start + 1, '#');
                if (hash_start){
                    *hash_start = '\0';
                    strcpy(loc->search, query_start + 1);
                    strcpy(loc->hash, hash_start + 1);
                }
                else{
                    strcpy(loc->search, query_start + 1);
                }
            }
            else{
                char *hash_start = strchr(url_copy, '#');
                if (hash_start){
                    *hash_start = '\0';
                    strcpy(loc->hash, hash_start + 1);
                }
                else{
                    strcpy(loc->pathname, "");
                    strcpy(loc->search, "");
                    strcpy(loc->hash, "");
                }
            }
        }
    }
    else{
        strcpy(loc->pathname, "");
        strcpy(loc->search, "");
        strcpy(loc->hash, "");
    }

    return loc;
}