/**
* @file list.h
 * @brief List utilities
 * @date 2025-08-23
 * @author Tilo
 */

#ifndef TSTD_LIST_H
#define TSTD_LIST_H
#include <stdlib.h>
#include <stdlib.h>

typedef struct {
    /**
     * @brief Pointer to the list's underlying data storage.
     *
     * This member variable represents the dynamic array used to store the actual
     * elements of the list. Each element is a pointer, allowing the list to
     * store arbitrary data types. The size of this array is managed by the
     * capacity member, and its content can grow or shrink dynamically when
     * elements are added or removed.
     *
     * The memory for this array is allocated dynamically and should be freed
     * appropriately to avoid memory leaks when the list is no longer needed.
     */
    void** data;
    /**
     * @brief Represents the number of elements currently stored in the list.
     *
     * This member tracks the current count of valid elements within the list. It
     * increases when elements are added and decreases when elements are removed.
     * It is always less than or equal to the list's capacity.
     */
    size_t length;
    /**
     * @brief Represents the current capacity of the list.
     *
     * This member defines the maximum number of elements the list can hold
     * before needing to reallocate memory for additional space. It dynamically
     * increases as needed when elements are added beyond the current capacity.
     */
    size_t capacity;
} list;

/**
 * @brief Creates a new list with a default initial capacity.
 *
 * This function initializes a new empty list using a pre-defined default
 * capacity. The created list can later hold elements and be resized
 * dynamically as needed.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation fails.
 */
list* list_create();


/**
 * @brief Creates a new list with a specified initial capacity.
 *
 * This function initializes an empty list with the given capacity. The capacity
 * determines the maximum number of elements the list can initially hold before
 * requiring a resize operation. The list supports dynamic resizing as more
 * elements are added beyond its current capacity.
 *
 * @param capacity The initial number of elements the list can hold.
 * @return A pointer to the newly created list, or NULL if memory allocation fails.
 */
list* list_create_with_capacity(size_t capacity);

/**
 * @brief Resizes the capacity of the list to accommodate more elements.
 *
 * This function dynamically increases the capacity of a list when needed.
 * A new memory block is allocated, existing elements are copied to the
 * new block, and the old memory is freed. The new capacity is determined
 * based on a growth factor to optimize memory usage.
 *
 * @param list A pointer to the list structure to be resized.
 */
void list_resize(list* list);

/**
 * @brief Adds a new element to the end of the list.
 *
 * This function appends the provided element to the list. If the list has
 * reached its current capacity, it will automatically resize to ensure
 * there is enough space for the new element.
 *
 * @param list A pointer to the list structure where the element will be added.
 * @param element A pointer to the element being inserted into the list.
 */
void list_add_element(list* list, void* element);

/**
 * @brief Frees the memory allocated for the list and its elements.
 *
 * This function releases all resources associated with the provided list.
 * It deallocates the memory reserved for the list's data and the list
 * structure itself. After calling this function, the list pointer will
 * no longer be valid.
 *
 * @param list A pointer to the list to be freed. Must be a valid pointer
 *        to a list created with `list_create`, or NULL.
 */
void list_free(list* list);

/**
 * @brief Frees all elements and associated memory in the given list.
 *
 * This function deallocates the memory of each element contained in the list,
 * as well as the list's internal data structure and the list itself. After
 * calling this function, the given list pointer becomes invalid and should not
 * be used further.
 *
 * @param list A pointer to the list to be freed. Passing a NULL pointer is undefined behavior.
 */
void list_free_elements(list* list);

/**
 * @brief Deletes an element from the list at a specified index.
 *
 * This function removes the element at the given index from the list, reducing
 * the list's length by one. The subsequent elements in the list are shifted
 * to fill the gap left by the removed element. The memory for the removed
 * element is not freed by this function; it is the caller's responsibility to
 * manage the memory of the deleted element.
 *
 * @param list A pointer to the list from which the element will be deleted.
 * @param index The index of the element to remove. It must be a valid index
 *              within the list's current length.
 * @return A pointer to the removed element. The caller is responsible for managing
 *         the returned pointer, including deallocating memory if necessary.
 */
void* list_delete_element(list* list, int index);

#endif //TSTD_LIST_H
