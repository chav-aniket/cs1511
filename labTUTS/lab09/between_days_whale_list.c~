#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SPECIES_NAME_LENGTH 4096

// a struct to represent the date
// a whale pod sighting was made

struct date {
    int year;
    int month;
    int day;
};

// a struct to represent a sighting
// of a pod (group) of whales

struct pod {
    struct pod  *next;
    struct date *when;
    int         how_many;
    char        *species;
};


struct pod *read_sightings_file(char filename[]);
struct pod *read_sighting(FILE *f);
struct date *read_date(FILE *f);
struct date *string_to_date(char *s);

void print_function(struct pod *current, struct date *start_day, 
                    struct date *finish_day);
int check_range(struct pod *current, struct date *start_day, 
                struct date *finish_day);
void between_days_whales(struct pod *first_pod, struct date *start_day, struct date *finish_day);

// PUT YOUR FUNCTION DEFINITIONS HERE

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <file> <start-day> <finish-day>\n", argv[0]);
        return 1;
    }

    struct pod *first_pod = read_sightings_file(argv[1]);
    struct date *start_day = string_to_date(argv[2]);
    struct date *finish_day = string_to_date(argv[3]);

    between_days_whales(first_pod, start_day, finish_day);

    return 0;
}


//
// Print the whale sightings between start_day and finish_day inclusive.
// One line containing number of whales and species is printed for each sighting.
//

void print_function(struct pod *current, struct date *start_day, 
                    struct date *finish_day) {
    if (current->when->day < 10) {
        printf("0%d/",current->when->day);
    } else {
        printf("%d/",current->when->day);
    }
    if (current->when->month < 10) {
        printf("0%d/",current->when->month);
    } else {
        printf("%d/",current->when->month);
    }
    printf("%d",current->when->year);
    printf(" %d", current->how_many);
    printf(" %s\n", current->species);
    return;
}

int check_range(struct pod *current, struct date *start_day, 
                struct date *finish_day) {
    int c_year = current->when->year;
    int c_month = current->when->month;
    int c_day = current->when->day;
    
    int s_year = start_day->year;
    int f_year = finish_day->year;
    int s_month = start_day->month;
    int f_month = finish_day->month;
    int s_day = start_day->day;
    int f_day = finish_day->day;
    
    if (c_year == s_year && c_year == f_year) {
        if (c_month == s_month && c_month == f_month) {
            if (c_day >= s_day && c_day <= f_day) {
                return 1;
            }
        } else if (c_month == s_month && c_month != f_month) {
            if (c_day >= s_day) {
                return 1;
            }
        } else if (c_month > s_month && c_month < f_month) {
            return 1;
        } else if (c_month != s_month && c_month == f_month) {
            if (c_day <= f_day) {
                return 1;
            }
        }
    } else if (c_year == s_year && c_year != f_year) {
        if (c_month == s_month && c_day >= s_day) {
            return 1;
        } else if (c_month > s_month) {
            return 1;
        }
    } else if (c_year > s_year && c_year < f_year) {
        return 1;
    } else if (c_year != s_year && c_year == f_year) {
        if (c_month == f_month && c_day <= f_day) {
            return 1;
        } else if (c_month < f_month) {
            return 1;
        }
    }
    return 0;
}

void between_days_whales(struct pod *first_pod, struct date *start_day, struct date *finish_day) {
    struct pod *current = first_pod;
    
    while (current != NULL) {
        if(check_range(current, start_day, finish_day)) {
            print_function(current, start_day, finish_day);
        }
        current = current->next;
    }
    return;
}

// PUT YOUR FUNCTIONS HERE


//
// DO NOT CHANGE THE FUNCTIONS BELOW HERE
//

// return linked list of sightings read from filename
// exit called if there is an error

struct pod *read_sightings_file(char filename[]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        fprintf(stderr,"error: file '%s' can not open\n", filename);
        exit(1);
    }

    struct pod *first_sighting = NULL;
    struct pod *last_sighting = NULL;

    struct pod *sighting = read_sighting(f);
    while (sighting != NULL) {
        if (first_sighting == NULL) {
            first_sighting = sighting;
            first_sighting->next = NULL;
        } else {
            last_sighting->next = sighting;
        }
        last_sighting = sighting;
        sighting = read_sighting(f);
    }

    return first_sighting;
}


// read a whale sighting (date, number of whales, whale species)
// return a pointer to a malloced struct containing these details
// return NULL if a sighting can not be read

struct pod *read_sighting(FILE *f) {
    struct pod *p = malloc(sizeof (struct pod));
    if (p == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }

    p->next = NULL;

    p->when = read_date(f);
    if (p->when == NULL) {
        free(p);
        return NULL;
    }

    int n_scanned = fscanf(f, "%d", &(p->how_many));
    if (n_scanned != 1) {
        free(p);
        return NULL;
    }

    fgetc(f);
    char species_buffer[MAX_SPECIES_NAME_LENGTH];
    if (fgets(species_buffer, MAX_SPECIES_NAME_LENGTH, f) == NULL) {
        free(p);
        return NULL;
    }
   // finish string at '\n' if there is one
    char *newline_ptr = strchr(species_buffer, '\n');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    // also finish string at '\r' if there is one - files from Windows  will
    newline_ptr = strchr(species_buffer, '\r');
    if (newline_ptr != NULL) {
        *newline_ptr = '\0';
    }

    // malloc a char array long enough to hold species name
    // and copy species to it
    p->species = malloc(strlen(species_buffer) + 1);
    if (p->species == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    strcpy(p->species, species_buffer);

    return p;
}


// read a date in day/month/year format from stream f
// return a pointer to a malloced date struct containing them
//  return NULL if a date can not be read

struct date *read_date(FILE *f) {
    struct date *d = malloc(sizeof (struct date));
    if (d == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    int n_scanned = fscanf(f, "%d/%d/%d", &(d->day), &(d->month), &(d->year));
    if (n_scanned != 3) {
        free(d);
        return NULL;
    }
    return d;
}


// given a string containing a date in day/month/year format
// return a pointer to a malloced date struct containing them
// return NULL if a date can not be read

struct date *string_to_date(char *s) {
    struct date *d = malloc(sizeof (struct date));
    if (d == NULL) {
        fprintf(stderr, "out of memory\n");
        exit(1);
    }
    int n_scanned = sscanf(s, "%d/%d/%d", &(d->day), &(d->month), &(d->year));
    if (n_scanned != 3) {
        free(d);
        return NULL;
    }
    return d;
}
