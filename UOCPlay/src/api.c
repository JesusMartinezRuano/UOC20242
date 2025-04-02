#include <stdio.h>
#include <assert.h>
#include "csv.h"
#include "api.h"
#include <string.h>

// Get the API version information
const char* api_version()
{
    return "UOC PP 20242";
}

// Load data from a CSV file. If reset is true, remove previous data
tApiError api_loadData(tApiData* data, const char* filename, bool reset)
{
    tApiError error;
    FILE *fin;    
    char buffer[FILE_READ_BUFFER_SIZE];
    tCSVEntry entry;
    
    // Check input data
    assert( data != NULL );
    assert(filename != NULL);
    
    // Reset current data    
    if (reset) {
        // Remove previous information
        error = api_freeData(data);
        if (error != E_SUCCESS) {
            return error;
        }
        
        // Initialize the data
        error = api_initData(data);
        if (error != E_SUCCESS) {
            return error;
        }
    }

    // Open the input file
    fin = fopen(filename, "r");
    if (fin == NULL) {
        return E_FILE_NOT_FOUND;
    }
    
    // Read file line by line
    while (fgets(buffer, FILE_READ_BUFFER_SIZE, fin)) {
        // Remove new line character     
        buffer[strcspn(buffer, "\n\r")] = '\0';
        
        csv_initEntry(&entry);
        csv_parseEntry(&entry, buffer, NULL);
        // Add this new entry to the api Data
        error = api_addDataEntry(data, entry);
        if (error != E_SUCCESS) {
			csv_freeEntry(&entry);
			fclose(fin);
            return error;
        }
        csv_freeEntry(&entry);

    }
    
    fclose(fin);
    
    return E_SUCCESS;
}

// Initialize the data structure
tApiError api_initData(tApiData* data) {
    assert(data != NULL);

    // Inicializar la lista de personas
    tApiError error = people_init(&data->people); // Cambiado de personList a people
    if (error != E_SUCCESS) {
        return error;
    }

    // Inicializar la lista de suscripciones
    error = subscriptions_init(&data->subscriptionList);
    if (error != E_SUCCESS) {
        return error;
    }

    // Inicializar el catálogo de películas
    error = catalog_init(&data->catalog);
    if (error != E_SUCCESS) {
        return error;
    }

    return E_SUCCESS;
}

// Add a person into the data if it does not exist
tApiError api_addPerson(tApiData* data, tCSVEntry entry) {
	/////////////////////////////////
	// PR1_3c
	/////////////////////////////////
	
	/////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Add a subscription if it does not exist
tApiError api_addSubscription(tApiData* data, tCSVEntry entry) {
	/////////////////////////////////
	// PR1_3d
	/////////////////////////////////
	
	/////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Add a film if it does not exist
tApiError api_addFilm(tApiData* data, tCSVEntry entry) {
	/////////////////////////////////
	// PR1_3e
	/////////////////////////////////
	
	/////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Get the number of people registered on the application
int api_peopleCount(tApiData data) {
	/////////////////////////////////
	// PR1_3f
	/////////////////////////////////
	
	/////////////////////////////////
    return -1;
}

// Get the number of subscriptions registered on the application
int api_subscriptionsCount(tApiData data) {
	/////////////////////////////////
	// PR1_3f
	/////////////////////////////////
	
	/////////////////////////////////
    return -1;
}

// Get the number of films registered on the application
int api_filmsCount(tApiData data) {
	/////////////////////////////////
	// PR1_3f
	/////////////////////////////////
	
	/////////////////////////////////
    return -1;
}

// Get the number of free films registered on the application
int api_freeFilmsCount(tApiData data) {
	/////////////////////////////////
	// PR1_3f
	/////////////////////////////////
	
	/////////////////////////////////
    return -1;
}

// Free all used memory
tApiError api_freeData(tApiData* data) {
	/////////////////////////////////
	// PR1_3g
	/////////////////////////////////
	
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Add a new entry
tApiError api_addDataEntry(tApiData* data, tCSVEntry entry) {
	/////////////////////////////////
	// PR1_3h
	/////////////////////////////////
	
    /////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Get subscription data
tApiError api_getSubscription(tApiData data, int id, tCSVEntry *entry) {
	/////////////////////////////////
	// PR1_4a
	/////////////////////////////////
	
	/////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Get film data
tApiError api_getFilm(tApiData data, const char* name, tCSVEntry *entry) {
	/////////////////////////////////
	// PR1_4b
	/////////////////////////////////
	
	/////////////////////////////////
	return E_NOT_IMPLEMENTED;
}

// Get free films data
tApiError api_getFreeFilms(tApiData data, tCSVData *freeFilms) {
	/////////////////////////////////
	// PR1_4c
	/////////////////////////////////
	
	/////////////////////////////////
    return E_NOT_IMPLEMENTED;
}

// Get films data by genre
tApiError api_getFilmsByGenre(tApiData data, tCSVData *films, int genre) {
	/////////////////////////////////
	// PR1_4d
	/////////////////////////////////
	
	/////////////////////////////////
    return E_NOT_IMPLEMENTED;
}
