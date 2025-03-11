const fs = require("fs");
const input = fs.readFileSync(0).toString().trim().split("\n");

const n = Number(input[0]);
const commands = input.slice(1, n + 1);

class Node {
    constructor(num) {
        this.prev = null;
        this.next = null;
        this.data = num;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.nodeNum = 0;
    }

    pushFront(num) {
        const newNode = new Node(num);

        if (this.head === null) { 
            this.tail = newNode;
        } else {
            newNode.next = this.head;
            newNode.prev = null;
            this.head.prev = newNode;
        }

        this.head = newNode;
        this.nodeNum++;
    }

    pushBack(num) {
        const newNode = new Node(num);

        if (this.tail === null) {
            this.head = newNode;
        } else {
            newNode.prev = this.tail;
            newNode.next = null;
            this.tail.next = newNode;
        }
        this.tail = newNode;
        this.nodeNum++;
    }

    popFront() {
        if (this.nodeNum === 0) {
            throw new Error('empty list');
        }
        const curNum = this.head.data; 
        if (this.nodeNum === 1) {
            this.head = null;
            this.tail = null;
        }
        else {
            this.head.prev = null;
            this.head = this.head.next;
        }
        this.nodeNum--;
        return curNum;
    }

    popBack() {
        if (this.nodeNum === 0) {
            throw new Error('empty list');
        }
        const curNum = this.tail.data;
        if (this.nodeNum === 1) {
            this.head = null;
            this.tail = null;
        }
        else {
            this.tail.next = null;
            this.tail = this.tail.prev;
        }
        this.nodeNum--;
        return curNum;
    }

    size() {
        return this.nodeNum;
    }

    empty() {
        return this.nodeNum === 0;
    }

    front() {
        if (this.nodeNum === 0) {
            throw new Error('empty list');
        }
        return this.head.data;

    }

    back() {
        if (this.nodeNum === 0) {
            throw new Error('empty list');
        }
        return this.tail.data;
    }
}

const DLL = new DoublyLinkedList();


for (let i = 0; i < n; i++) {
    const [command, num] = commands[i].split(' ');
    switch (command) {
        case "push_front":
            DLL.pushFront(num);
            break;
        case "push_back":
            DLL.pushBack(num);
            break;
        case "pop_front":
            console.log(DLL.popFront());
            break;
        case "pop_back":
            console.log(DLL.popBack());
            break;
        case "size":
            console.log(DLL.size());
            break;
        case "empty":
            console.log(Number(DLL.empty()));
            break;
        case "front":
            console.log(DLL.front());
            break;
        case "back":
            console.log(DLL.back());
            break;
        default:
            throw new Error(`unsupported command ${command}`);
    }
}