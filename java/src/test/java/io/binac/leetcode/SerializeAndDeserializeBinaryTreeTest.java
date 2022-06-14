package io.binac.leetcode;

import io.binac.leetcode.util.TreeNode;
import io.binac.leetcode.util.Trees;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class SerializeAndDeserializeBinaryTreeTest {

    @Test
    void test1() {
        SerializeAndDeserializeBinaryTree.Codec codec = new SerializeAndDeserializeBinaryTree.Codec();

        TreeNode root1 = Trees.asTree(1, 2, 3, null, null, 4, 5);
        assertTrue(Trees.equals(codec.deserialize(codec.serialize(root1)), root1));

        TreeNode root2 = Trees.asTree();
        assertTrue(Trees.equals(codec.deserialize(codec.serialize(root2)), root2));
    }
}