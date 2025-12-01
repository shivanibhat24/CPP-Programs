const size_t BUFFER_SIZE = 0x30000000;
alignas (std::max_align_t) char buffer[BUFFER_SIZE];
size_t buffer_pos = 0;

void *
operator new (size_t size)
{
    constexpr std::size_t alignment = alignof (std::max_align_t);
    size_t padding = (alignment - (buffer_pos % alignment)) % alignment;
    size_t total_size = size + padding;
    char *aligned_ptr = &buffer[buffer_pos + padding];
    buffer_pos += total_size;
    return aligned_ptr;
}

void
operator delete (void * /*unused*/, unsigned long /*unused*/) noexcept
{
}
void
operator delete (void * /*unused*/) noexcept
{
}
void
operator delete[] (void * /*unused*/) noexcept
{
}
void
operator delete[] (void * /*unused*/, size_t /*unused*/) noexcept
{
}
class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;
        queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; ++i)
            {
                Node* curr = q.front();
                q.pop();
                if(i == size - 1) curr->next = nullptr;
                else curr->next = q.front();
                if(curr->left)
                {
                    q.push(curr->left);
                    q.push(curr->right);
                }
            }
        }

        return root;
    }
};
