
#include <memory>
using std::shared_ptr;

// On Page 310
template<typename T>
class BinarySearchTree {
	private:
		class TreeNode {
			public:
				T data;
				shared_ptr<TreeNode> left, right;
		};

		void clear(shared_ptr<TreeNode> &n) {
			if (n) {
				clear(n->left); 
				clear(n->right);
				n = nullptr;
			}
		}

		// 
		void replaceParentChildLink(shared_ptr<TreeNode> par,
				shared_ptr<TreeNode> child,
				shared_ptr<TreeNode> new_link) {

			if (!par) {
				return;
			}

			if (par->left == child) {
				par->left = new_link;

			} else {
				par->right = new_link;
			}
		}

		shared_ptr<TreeNode> root;

	public:
		BinarySearchTree(void) : root(nullptr) {}

		~BinarySearchTree(void) {
			clear();
		}

		const bool empty(void) const {
			return !root;
		}

		void clear(void) {
			clear(root);
		}

		const bool insert(const T &key) {

			shared_ptr<TreeNode> t = shared_ptr<TreeNode>(new TreeNode{key, nullptr, nullptr});
			shared_ptr<TreeNode> par = nullptr;

			if (empty()) {
				root = t;
				return true;
			}

			shared_ptr<TreeNode> curr;
			curr = root;

			while(curr) {
				par = curr;
				if ( t->data == curr->data) {
					// Note the explicit assignment to destroy the TreeNode
					// object.
					t = nullptr;
					return false;

				} else if (t->data < curr->data) {
					curr = curr->left;

				} else {
					curr = curr->right;
				}
			}

			if (t->data < par->data) {
				par->left = t;

			} else {
				par->right = t;
			}

			return true;
		}

		const bool erase(const T &key) {

			// Find the node with key
			shared_ptr<TreeNode> curr = root, par = nullptr;
			
			while(curr && curr->data != key) {
				par = curr;
				curr = key < curr->data ? curr->left : curr->right;
			}

			if(!curr) {
				return false;
			}

			if (curr->right) {
				// Find the minimum of the right subtree
				shared_ptr<TreeNode> r_curr = curr->right, r_par = curr;
				while(r_curr->left) {
					r_par = r_curr;
					r_curr = r_curr->left;
				}

				// Move links to erase the node
				replaceParentChildLink(par, curr, r_curr);
				replaceParentChildLink(r_par, r_curr, r_curr->right);
				r_curr->left = curr->left;
				r_curr->right = curr->right;

				if (root == curr) {
					root = r_curr;
				}

			} else {
				if (root == curr) {
					root = curr->left;
				}

				replaceParentChildLink(par, curr, curr->left);
			}

			curr = nullptr;
			return true;
		}
};

int main(int argc, char **argv) {

}
