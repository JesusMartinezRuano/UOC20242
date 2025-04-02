#ifndef __UOCPLAY_API__H
#define __UOCPLAY_API__H
#include <stdbool.h>
#include "error.h"
#include "csv.h"
#include "person.h"
#include "subscription.h"
#include "film.h"

#define FILE_READ_BUFFER_SIZE 2048

// Estructura para almacenar los datos de la API
typedef struct _ApiData {
    tPeople people;                  // Lista de personas
    tSubscriptions subscriptionList; // Lista de suscripciones
    tCatalog catalog;                // Catálogo de películas
} tApiData;

// Get the API version information
const char* api_version();

// Load data from a CSV file. If reset is true, remove previous data
tApiError api_loadData(tApiData* data, const char* filename, bool reset);

// Initialize the data structure
tApiError api_initData(tApiData* data);

// Add a person into the data if it does not exist
tApiError api_addPerson(tApiData* data, tCSVEntry entry);

// Add a subscription if it does not exist
tApiError api_addSubscription(tApiData* data, tCSVEntry entry);

// Add a film if it does not exist
tApiError api_addFilm(tApiData* data, tCSVEntry entry);

// Get the number of people registered on the application
int api_peopleCount(tApiData data);

// Get the number of subscriptions registered on the application
int api_subscriptionsCount(tApiData data);

// Get the number of films registered on the application
int api_filmsCount(tApiData data);

// Get the number of free films registered on the application
int api_freeFilmsCount(tApiData data);

// Free all used memory
tApiError api_freeData(tApiData* data);

// Add a new entry
tApiError api_addDataEntry(tApiData* data, tCSVEntry entry);

// Get subscription data
tApiError api_getSubscription(tApiData data, int id, tCSVEntry *entry);

// Get film data
tApiError api_getFilm(tApiData data, const char* name, tCSVEntry *entry);

// Get free films data
tApiError api_getFreeFilms(tApiData data, tCSVData *freeFilms);

// Get films data by genre
tApiError api_getFilmsByGenre(tApiData data, tCSVData *films, int genre);

#endif // __UOCPLAY_API__H
