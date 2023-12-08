# Inventory and Order Management System

## Overview

The Inventory and Order Management System is a C++ program that facilitates the management of items, orders, and promotions. It includes features for adding new items, viewing item types, placing orders, and managing order details. The program is designed using a doubly linked list structure for efficient data management.

## Features

- **Item Structure:** Represents details of each item, including ID, type, quantity, price, and availability for sale.
- **Doubly Linked List:** Utilizes a doubly linked list to efficiently manage items and orders.
- **Order Class:** Represents an order with client details, item list, total price, and checkout status.
- **Manage Class:** Manages operations related to items and orders, such as adding new items, placing orders, and modifying orders.

## Usage

1. Compile the C++ program using a C++ compiler.
2. Run the executable to start the Inventory and Order Management System.
3. Use the provided menu to navigate through different features.
4. Manage items, place orders, and perform order-related operations.

## Classes

### `item` Structure

- Represents details of each item, including ID, type, quantity, price, and availability for sale.
- Provides methods for comparisons and printing.

### `Node` Structure

- Represents a node in a doubly linked list.
- Holds data of type T.
- Includes next and previous pointers.

### `DoublyLinkedList` Class

- Implements a doubly linked list for managing items and orders.
- Provides methods for insertion, deletion, sorting, and printing.

### `Order` Class

- Represents an order with client details, item list, total price, and checkout status.
- Provides methods for order-related operations, such as adding items, removing items, and checking out.

### `Manage` Class

- Manages operations related to items and orders.
- Includes methods for adding new items, placing orders, modifying orders, and removing orders.

## System Usage

1. **Add New Item:** Add a new item with details such as ID, type, quantity, price, and availability for sale.

2. **View Items Sorted by Price:** View all items sorted by their prices.

3. **View Promotion Items:** View items that are available for sale.

4. **View All Items of a Type:** View items of a specific type.

5. **Place Order:** Place a new order by entering client details and selecting items.

6. **View Orders Sorted by Price:** View all orders sorted by their total prices.

7. **Checkout Order:** Mark an order as checked out.

8. **Modify Order:** Update client details for an existing order.

9. **Remove Order:** Delete an order from the system.

10. **Exit:** Exit the program.

## Contributions

Contributions are welcome! If you wish to contribute, please follow the guidelines in the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details.
