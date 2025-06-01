struct Song {
    string title;
    string artist;
    string genre;
    unsigned int duration; // seconds
    Song *next;            // next pointer
};


// Sum over list (total duration)
unsigned int totalDuration(Song *head) {
    unsigned int sum = 0;
    Song *curr = head;
    while (curr) {
        sum += curr->duration;
        curr = curr->next;
    }
    return sum;
}
// Filter/list-copy ("find all by genre")
// returns a NEW singly-linked list of clones, preserving order
Song* filterByGenre(Song *head, const string &genre) {
    Song *newHead = nullptr, *newTail = nullptr;
    for (Song *curr = head; curr; curr = curr->next) {
        if (curr->genre == genre) {
            Song *copy = new Song{curr->title, curr->artist, curr->genre, curr->duration, nullptr};
            if (!newHead) {
                newHead = newTail = copy;
            } else {
                newTail->next = copy;
                newTail = copy;
            }
        }
    }
    return newHead;
}

// 