 template <class T> inline void hash_combine(std::size_t& seed, const T& v) {
    std::hash<T> hasher;
    seed ^= hasher(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}


inline const auto optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();
class Solution {
    struct Node {
        std::string_view name;
        std::map<std::string_view, std::unique_ptr<Node>> children;
        bool marked{false};
        std::size_t
        hash(std::unordered_map<std::size_t, std::vector<Node*>>& dir) {
            if (children.size() == 0)
                return 0;
            std::size_t ourHash = 0;
            for (const auto& child : children) {
                hash_combine(ourHash, child.first);
                auto theirHash = child.second->hash(dir);
                hash_combine(ourHash, theirHash);
            }

            dir[ourHash].emplace_back(this);
            return ourHash;
        }

        void pushOut(std::vector<std::vector<std::string>>& dirs,
                     std::vector<std::string>& cur) {
            if (marked)
                return;

            if (name != "/")
                dirs.push_back(cur);

            for (const auto& [cName, child] : children) {
                cur.emplace_back(cName);
                child->pushOut(dirs, cur);
                cur.pop_back();
            }
        }
    };

public:
    static std::vector<std::vector<std::string>>
    deleteDuplicateFolder(const std::vector<std::vector<std::string>>& paths) {
        Node root{"/"sv};

        for (const auto& path : paths) {
            Node* cur = &root;
            for (const auto& dir : path) {
                if (auto it = cur->children.find(dir);
                    it != cur->children.end()) {
                    cur = it->second.get();
                    continue;
                }

                auto newNode = std::make_unique<Node>(dir);
                auto hey = newNode.get();
                cur->children.emplace(dir, std::move(newNode));
                cur = hey;
            }
        }

        // now we just need to
        std::unordered_map<std::size_t, std::vector<Node*>> groups;
        root.hash(groups);

        for (const auto& [hash, group] : groups) {
            if (group.size() < 2)
                continue;

            for (const auto& node : group)
                node->marked = true;
        }

        std::vector<std::vector<std::string>> out;
        std::vector<std::string> tmp;
        root.pushOut(out, tmp);
        return out;
    }
};
